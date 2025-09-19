class Spreadsheet:
    
    def __init__(self, rows: int):
        self.rows = rows
        self.cols = 26 # from A to Z
        self.sheet = [[0] * self.cols for _ in range(self.rows)]
        self.alphabets = {chr(ord('A') + i) for i in range(26)}
            
    def setCell(self, cell: str, value: int) -> None:
        col = ord(cell[0]) - ord('A')
        row = int(cell[1 : ]) - 1 # cause cell is giving 1-indexed
        self.sheet[row][col] = value

    def resetCell(self, cell: str) -> None:
        col = ord(cell[0]) - ord('A')
        row = int(cell[1 : ]) - 1
        self.sheet[row][col] = 0

    def getValue(self, formula: str) -> int:
        # 1st ch is '=' so remove this
        formula = formula[1 : ]
        # now extract 2 parts berfore and after the operator
        part1 , part2 = formula.split('+')
        
        return self._getVal(part1) + self._getVal(part2) 
    
    def _getVal(self , s: str) -> int:
        # check s is index or normal value
        if s[0] not in self.alphabets:
            return int(s)
        
        # extract the index
        col = ord(s[0]) - ord('A')
        row = int(s[1 : ]) - 1
        return self.sheet[row][col] 
        

spreadsheet = Spreadsheet(3)
print(spreadsheet.getValue("=5+7")) # returns 12 (5+7)
spreadsheet.setCell("A1", 10) # sets A1 to 10
print(spreadsheet.getValue("=A1+6")) # returns 16 (10+6)
spreadsheet.setCell("B2", 15) # sets B2 to 15
print(spreadsheet.getValue("=A1+B2")) # returns 25 (10+15)
spreadsheet.resetCell("A1") # resets A1 to 0
print(spreadsheet.getValue("=A1+B2")) # returns 15 (0+15)