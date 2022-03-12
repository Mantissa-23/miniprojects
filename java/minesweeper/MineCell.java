import java.awt.Graphics;
import javax.swing.ImageIcon;
import java.awt.Image;

public class MineCell {
  private String status;
  private int row;
  private int col;

  public MineCell(int row, int column) {
    this.row = row;
    this.col = column;
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

  public Image getImage() {
    String filename = "img/covered_cell.png";

    if(this.status.equals(Configuration.STATUS_OPENED))
      filename = "img/mine_cell.png";
    else if(this.status.equals(Configuration.STATUS_MARKED))
      filename = "img/marked_cell.png";

    ImageIcon icon = new ImageIcon(filename);
    return icon.getImage();
  }
}
