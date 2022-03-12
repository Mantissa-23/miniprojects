import java.util.Random;
import java.awt.Graphics;

public class Minefield
{
  private Object[][] field;
  private int numRows;
  private int numCols;
  private int numMines;

  public Minefield(int numRows, int numCols, int numMines) {
    this.numRows = numRows;
    this.numCols = numCols;
    this.numMines = numMines;
    this.field = new Object[numCols][numRows];
    this.mineLaying(numMines);
    this.addInfoCells();
  }

	public Minefield() {
    this(10, 10, 10);
	}

  public void mineLaying(int numOfMines, String distribution) {
    this.mineLaying(numOfMines);
  }

  public void mineLaying(int numOfMines) {
    Random r = new Random();
    int currentMineCount = 0;
    while(currentMineCount < numOfMines) {
      int row = r.nextInt(this.numRows);
      int col = r.nextInt(this.numCols);
      if(this.field[col][row] == null) {
        this.field[col][row] = new MineCell(row, col);
        currentMineCount++;
      }
    }
  }

  private int countMinesAroundCoordinates(int row, int col) {
    int count = 0;
    for(int i = -1; i < 2; i++) {
      for(int j = -1; j < 2; j++) {
        int subCol = i + col;
        int subRow = j + row;
        if(this.validateRowCol(subRow, subCol) && this.getCellByRowCol(subRow, subCol) instanceof MineCell)
          count++;
      }
    }

    return count;
  }

  public void addInfoCells() {
    for(int col = 0; col < this.numCols; col++) {
      for(int row = 0; row < this.numRows; row++) {
        if(this.field[col][row] == null) {
          this.field[col][row] = new InfoCell(row, col, this.countMinesAroundCoordinates(row, col));
        }
      }
    }
  }

  private boolean validateRowCol(int row, int col) {
    return row >= 0 && row < this.numRows && col >= 0 && col < this.numCols;
  }

  public Object getCellByRowCol(int row, int col) {
    if(validateRowCol(row, col))
      return field[col][row];
    return null;
  }

  public Object getCellByScreenCoordinates(int x, int y) {
    int row = y / Configuration.CELL_SIZE;
    int col = x / Configuration.CELL_SIZE;
    
    return this.getCellByRowCol(row, col);
  }

  public void setMineCell(int row, int col, MineCell cell) {
    if(validateRowCol(row, col))
      field[col][row] = cell;
  }

  public void setInfoCell(int row, int col, InfoCell cell) {
    if(validateRowCol(row, col))
      field[col][row] = cell;
  }

  public int countCellsWithStatus(String status) {
    int count = 0;
    for(int row = 0; row < this.numRows; row++) {
      for(int col = 0; col < this.numCols; col++) {
        if(field[col][row] instanceof MineCell) {
          MineCell mineCell = (MineCell) field[col][row];
          if(mineCell.getStatus().equals(status))
            count++;
        } else if (field[col][row] instanceof InfoCell) {
          InfoCell infoCell = (InfoCell) field[col][row];
          if(infoCell.getStatus().equals(status))
            count++;
        }
      }
    }
    return count;
  }

  public void openCells(Object cell) {
    // Do nothing if it's a mine; duh, you lost idiot
    if(cell instanceof MineCell)
      return;
    else if(cell instanceof InfoCell) {
      InfoCell infoCell = (InfoCell) cell;
      if(infoCell.getNumOfAdjacentMines() == 0) {
        for(int i = -1; i < 2; i++) {
          for(int j = -1; j < 2; j++) {
            int subCol = i + infoCell.getHorizontalPosition() / Configuration.CELL_SIZE;
            int subRow = j + infoCell.getVerticalPosition() / Configuration.CELL_SIZE;
            if(subCol >= 0 && subCol < this.numCols && subRow >= 0 && subRow < this.numRows && this.getCellByRowCol(subRow, subCol) instanceof InfoCell) {
              InfoCell subInfoCell = (InfoCell) this.getCellByRowCol(subRow, subCol);
              if(!subInfoCell.getStatus().equals(Configuration.STATUS_OPENED)) {
                subInfoCell.setStatus(Configuration.STATUS_OPENED);
                this.openCells(subInfoCell);
              }
            }
          }
        }
      } else {
        infoCell.setStatus(Configuration.STATUS_OPENED);
      }
    }
  }

  public void draw(Graphics g) {
    for(int col = 0; col < this.numCols; col++) {
      for(int row = 0; row < this.numRows; row++) {
        Object cell = this.field[col][row];
        if(cell instanceof MineCell) {
          MineCell mineCell = (MineCell) cell;
          mineCell.draw(g);
        } else if (cell instanceof InfoCell) {
          InfoCell infoCell = (InfoCell) cell;
          infoCell.draw(g);
        }
      }
    }
  }

  public void revealIncorrectMarkedCells() {
    for(int col = 0; col < this.numCols; col++) {
      for(int row = 0; row < this.numRows; row++) {
        if(this.getCellByRowCol(row, col) instanceof InfoCell) {
          InfoCell infoCell = (InfoCell) this.getCellByRowCol(row, col);
          if(infoCell.getStatus().equals(Configuration.STATUS_MARKED))
            infoCell.setStatus(Configuration.STATUS_WRONGLY_MARKED);
        } else if (this.getCellByRowCol(row, col) instanceof MineCell){
          MineCell mineCell = (MineCell) this.getCellByRowCol(row, col);
          mineCell.setStatus(Configuration.STATUS_OPENED);
        }
      }
    }
  }
}
