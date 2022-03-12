import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.Graphics;
import java.awt.Dimension;

public class Board extends JPanel
{
  private Minefield field;
  private int height;
  private int width;
  private int mineCount;
  private JLabel statusbar;
  private boolean gameOver;

	public Board(int height, int width, int mines, JLabel statusbar)
	{
    this.height = height;
    this.width = width;
    this.mineCount = mines;
    this.field = new Minefield(height, width, mines);
    this.statusbar = statusbar;
    this.gameOver = false;
		setPreferredSize(new Dimension(Configuration.BOARD_WIDTH, Configuration.BOARD_HEIGHT));
		addMouseListener(new MouseReader(this));
	}

	@Override
	public void paintComponent(Graphics g)
	{
    this.field.draw(g);
	}

  public Minefield getMinefield() {
    return this.field;
  }

  public boolean isGameOver() {
    return this.gameOver;
  }

  public void setStatusbar(String text) {
    this.statusbar.setText(text);
  }
      
  public String getStatusbar() {
    return this.statusbar.getText();
  }

  private int checkFlaggedMines() {
    return this.mineCount - field.countCellsWithStatus(Configuration.STATUS_MARKED);
  }

  public boolean removeMine() {
    int mineCount = checkFlaggedMines();
    boolean valid = this.checkFlaggedMines() - 1 >= 0;
    if(valid) {
      this.setStatusbar(String.format("%d mines remaining", mineCount));
    } else {
      this.setStatusbar("Invalid action");
    }
    return valid;
  }

  public boolean addMine() {
    int mineCount = checkFlaggedMines();
    boolean valid = mineCount + 1 <= this.mineCount;
    if(valid) {
      this.setStatusbar(String.format("%d mines remaining", mineCount));
    } else {
      this.setStatusbar("Invalid action");
    }
    return valid;
  }

	public void mouseClickOnLocation(int x, int y, String button)
	{
    if(!this.isGameOver()) {
      Object cell = this.field.getCellByScreenCoordinates(x, y);

      switch(button) {
        case "left":
          if(cell instanceof InfoCell) {
            InfoCell infoCell = (InfoCell) cell;
            field.openCells(infoCell);
            infoCell.setStatus(Configuration.STATUS_OPENED);
            if(field.countCellsWithStatus(Configuration.STATUS_OPENED) == this.width * this.height - mineCount) {
              this.setStatusbar("Game over - You won!");
              this.gameOver = true;
            }
          } else if (cell instanceof MineCell) {
            MineCell mineCell = (MineCell) cell;
            mineCell.setStatus(Configuration.STATUS_OPENED);
            this.setStatusbar("Game over - You lost!");
            field.revealIncorrectMarkedCells();
            this.gameOver = true;
          }
          break;
        case "right":
          if(cell instanceof InfoCell) {
            InfoCell infoCell = (InfoCell) cell;
            if(infoCell.getStatus().equals(Configuration.STATUS_COVERED)) {
              if(this.removeMine())
                infoCell.setStatus(Configuration.STATUS_MARKED);
            }
            else if(infoCell.getStatus().equals(Configuration.STATUS_MARKED)) {
              if(this.addMine())
                infoCell.setStatus(Configuration.STATUS_COVERED);
            }
          } else if (cell instanceof MineCell) {
            MineCell mineCell = (MineCell) cell;
            if(mineCell.getStatus().equals(Configuration.STATUS_COVERED)) {
              if(this.removeMine())
                mineCell.setStatus(Configuration.STATUS_MARKED);
            }
            else if(mineCell.getStatus().equals(Configuration.STATUS_MARKED)) {
              if(this.addMine())
                mineCell.setStatus(Configuration.STATUS_COVERED);
            }
          }
          break;
      }
      repaint();
    }
	}
}
