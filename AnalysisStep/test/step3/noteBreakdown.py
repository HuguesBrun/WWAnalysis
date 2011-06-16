from WWAnalysis.AnalysisStep.mcAnalysis import *
import sys

# def getTopPair(m,c,j):
#     i = 1 + 2*channels.index(c)
#     for line in open( 'topyields-{0}j-mc-scaled.txt'.format(j) )
#         if line.split()[0].strip() == str(m):
#             return ( line.split()[i],line.split()[i+1] )

# class TableMaker(MCAnalysis):
class TableMaker:
    def __init__(self,samples,options):
#         super(TableMaker,self).__init__(samples,options)
        self._options = options
        self._allData = {}
        self._ncol = options.ncol
        self._fOut = open(options.out.replace('%m',str(options.mass)).replace('%l',str(int(options.lumi*1000))),'w') if options.out!= "" else sys.stdout 
        self._order   = []
        for line in open(samples,'r'):
            field = line.split(':')
            rootfile = options.path+"/"+"tree_%s.root" % field[1].strip()
            if len(field) != 2 or field[0][0] == '#': continue
            fieldName = field[0].replace('%m',str(options.mass))
            if fieldName in self._order:                               self._allData[fieldName].append(TreeToYield(rootfile % options.mass if rootfile.find('%d') != -1 else rootfile,options))
            else                      : self._order.append(fieldName); self._allData[fieldName] =     [TreeToYield(rootfile % options.mass if rootfile.find('%d') != -1 else rootfile,options)]
    def getYields(self,cuts):
        ret = {}
        for key in self._allData:
            ret[key] = self._getYields(self._allData[key],cuts)
        return ret
    def printTable(self,report):
        self._printHeader()
        if self._options.final: self._printSummary(report)
        else:                   self._printBreakdown(report)
        self._printFooter()
    def _printHeader(self):
        print  >> self._fOut, "\\begin{table}[h!]\\begin{center}"
        print  >> self._fOut, "\\caption{{ {0} \\label{{ {1} }} }}".format(self._options.caption,self._options.out.split('.')[0] if self._options.out!= "" else "labelME" )
        self._fOut.write("\\begin{tabular}{|c|")
        for i in range(self._ncol) if self._ncol != 0 else self._order: self._fOut.write("c|")
        print  >> self._fOut, "}"
    def _printFooter(self):
        print  >> self._fOut, "\\end{tabular}\\end{center}\\end{table}"
    def _printSummary(self,report):
        S = len(self._order)                          #nSamples
        C = self._ncol if self._ncol != 0 else S+1    #nCol
        R = S / (C-1) + ((S%(C-1))>0)                 #n "row";  well nRow is really R*(nCuts+1)
        for r in range(R):
            print >> self._fOut, "\\hline"
            for sample in self._order[r*(C-1):min((r+1)*(C-1),S)]: 
                print >> self._fOut, " & {0}".format(sample),
            print >> self._fOut, " \\\\ \\hline"
            for i in range(len(report[self._order[0]][0][1])):
                if report[self._order[0]][0][1][i][0] == "all" : print >> self._fOut, "\\hline"
                print >> self._fOut, report[self._order[0]][0][1][i][0].replace('el','e').replace('mu','$\\mu$'),
                for sample in self._order[r*(C-1):min((r+1)*(C-1),S)]: 
                    fmt = " & ${0:.2f}\\pm{1:.2f}$"
                    if report[sample][-1][1][i][1] >  100: fmt = " & ${0:.1f}\\pm{1:.1f}$"
                    if report[sample][-1][1][i][1] > 1000: fmt = " & ${0:.0f}\\pm{1:.0f}$"
                    if sample == 'data': fmt = " & ${0:.0f}$" 
                    print >> self._fOut, fmt.format(report[sample][-1][1][i][1],report[sample][-1][1][i][2]),
                print >> self._fOut, "\\\\"
            print >> self._fOut, "\\hline"
    def _printBreakdown(self,report):
        S = len(self._order)                          #nSamples
        C = self._ncol if self._ncol != 0 else S+1    #nCol
        R = S / (C-1) + ((S%(C-1))>0)                 #n "row";  well nRow is really R*(nCuts+1)
        for r in range(R):
            print >> self._fOut, "\\hline"
            for sample in self._order[r*(C-1):min((r+1)*(C-1),S)]: 
                print >> self._fOut, " & {0}".format(sample),
            print >> self._fOut, " \\\\ \\hline"
            for i in range(len(report[self._order[0]])):
                if report[self._order[0]][i][0] == "entry point": continue
                print >> self._fOut, report[self._order[0]][i][0],
                for sample in self._order[r*(C-1):min((r+1)*(C-1),S)]: 
                    for channel in report[sample][i][1]: 
                        fmt = " & ${0:.1f}\\pm{1:.1f}$"
                        if channel[1] > 1000: fmt = " & ${0:.0f}\\pm{1:.0f}$"
                        if sample == 'data': fmt = " & ${0:.0f}$" 
                        if channel[0] == self._options.hypo: print >> self._fOut, fmt.format(channel[1],channel[2]),
                print >> self._fOut, "\\\\"
            print >> self._fOut, "\\hline"
    def _getYields(self,ttylist,cuts):
        return mergeReports([tty.getYields(cuts) for tty in ttylist])
        
if __name__ == "__main__":
    from optparse import OptionParser
    
    parser = OptionParser(usage="%prog [options] mcList.txt cuts.txt")
    addMCAnalysisOptions(parser)

    parser.add_option("-c", "--ncol",         dest="ncol",    type="int",    default="0",           help="number of columns in the table, gonna try to be smart here (default == nSamples)") 
    parser.add_option("-C", "--caption",      dest="caption", type="string", default="Caption Me!", help="caption at the top of the table") 
    parser.add_option("-H", "--hypo",         dest="hypo",    type="string", default="all",         help="which mode to use (ignored if -s)") 
#     parser.add_option("-o", "--out",      dest="out", type="string", default="",            help="out name (can will sub %m with mass, %l with lumi)")


    (options, args) = parser.parse_args()
    tm = TableMaker(args[0],options)
    cf  = CutsFile(args[1],options)
    report = tm.getYields(cf)
    tm.printTable(report)