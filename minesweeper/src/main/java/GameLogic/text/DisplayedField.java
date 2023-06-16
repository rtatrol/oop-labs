package GameLogic.text;

import java.util.Arrays;

import GameLogic.Field;

public class DisplayedField {

    private final char emptyCell = '?';
    private final char BOOM = '!';
    private final char flag = '*';
    private char[][] displayedField;

    public DisplayedField(int lineLength, int columnLength) {
        displayedField = new char[columnLength][lineLength];

        for (int i = 0; i < columnLength; i++) {
            Arrays.fill(displayedField[i], emptyCell);
        }
    }

    public void print() {
        for (char[] chars : displayedField) {
            for (char aChar : chars) {
                System.out.print(aChar);
            }
            System.out.print('\n');
        }
    }

    public void setCell(int i, int j, int value) {
        if (value >= 0) displayedField[i][j] = (char) ((char) value + '0');
        if (value == Field.BOOM) displayedField[i][j] = BOOM;
    }

    public void setFlag(int x, int y) {
        displayedField[x][y] = flag;
    }

    public void deleteFlag(int x, int y) {
        displayedField[x][y] = emptyCell;
    }
}