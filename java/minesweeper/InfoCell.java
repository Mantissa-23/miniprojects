import java.awt.Graphics;
import javax.swing.ImageIcon;
import java.awt.Image;

public class InfoCell {
  private String status;
  private int row;
  private int col;
  private int adjacentMines;

  public InfoCell(int row, int column, int numOfAdjacentMines) {
    this.row = row;
    this.col = column;
    this.adjacentMines = numOfAdjacentMines;
    this.status = Configuration.STATUS_COVERED;
  }

  public void draw(Graphics g) {
    g.drawImage(this.getImage(), this.getHorizontalPosition(), this.getVerticalPosition(), null);
  }

  public int getHorizontalPosition() {
    return this.col * Configuration.CELL_SIZE;
  }

  public int getVerticalPosition() {
    return this.row * Configuration.CELL_SIZE;
  }

  public String getStatus() {
    return this.status;
  }

  public void setStatus(String status) {
    this.status = status;
  }

  public int getNumOfAdjacentMines() {
    return this.adjacentMines;
  }

  public Image getImage() {
    String filename = "img/covered_cell.png";

    if(this.status.equals(Configuration.STATUS_OPENED))
      filename = String.format("img/info_%d.png", this.adjacentMines);
    else if(this.status.equals(Configuration.STATUS_MARKED))
      filename = "img/marked_cell.png";
    else if(this.status.equals(Configuration.STATUS_WRONGLY_MARKED))
      filename = "img/wrong_mark.png";

    ImageIcon icon = new ImageIcon(filename);
    return icon.getImage();
  }
}
