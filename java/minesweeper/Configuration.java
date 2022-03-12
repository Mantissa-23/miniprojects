import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class Configuration {
  public static int ROWS;
  public static int COLS;
  public static int CELL_SIZE;
  public static int MINES;
  public static int BOARD_WIDTH;
  public static int BOARD_HEIGHT;
  public static String STATUS_COVERED;
  public static String STATUS_OPENED;
  public static String STATUS_MARKED;
  public static String STATUS_WRONGLY_MARKED;

  public static void loadParameters(String filename) {
    try {
      final File config = new File(filename);
      final Scanner scanner = new Scanner(config);

      while (scanner.hasNextLine()) {
        String[] tokens = scanner.nextLine().split(" ");
        String fieldName = tokens[0];
        String value = tokens[1];
        switch (fieldName) {
          case "ROWS":
            Configuration.ROWS = Integer.parseInt(value);
            break;
          case "COLS":
            Configuration.COLS = Integer.parseInt(value);
            break;
          case "MINES":
            Configuration.MINES = Integer.parseInt(value);
            break;
          case "CELL_SIZE":
            Configuration.CELL_SIZE = Integer.parseInt(value);
            break;
          case "STATUS_OPENED":
            Configuration.STATUS_OPENED = value;
            break;
          case "STATUS_COVERED":
            Configuration.STATUS_COVERED = value;
            break;
          case "STATUS_MARKED":
            Configuration.STATUS_MARKED = value;
            break;
          case "STATUS_WRONGLY_MARKED":
            Configuration.STATUS_WRONGLY_MARKED = value;
            break;
        }
      }
      Configuration.BOARD_WIDTH = Configuration.COLS * Configuration.CELL_SIZE + 1;
      Configuration.BOARD_HEIGHT = Configuration.ROWS * Configuration.CELL_SIZE + 1;
      scanner.close();
    } catch (FileNotFoundException e) {
      System.exit(1);
    }

  }
}
