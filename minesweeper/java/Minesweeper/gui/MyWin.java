package minesweeper.java.Minesweeper.gui;

import java.awt.*;
import javax.swing.*;
import minesweeper.java.Minesweeper.Minesweeper;
import minesweeper.java.Minesweeper.exception.MinesweeperException;

public class MyWin extends JFrame {
    private final Context context;
    private final JPanel curPanel;

    public MyWin(Minesweeper game) {

        JPanel standardPanel = new JPanel(new BorderLayout());
        add(standardPanel);
        context = new Context(game, this);
        curPanel = new GamePanel(context);
        standardPanel.add(curPanel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }



    public  void openSettings() throws MinesweeperException {
        new SettingsPanel(context);

    }

    public void showRecordTable(){
        new RecordPanel(context.getGame().getRecordsTable());
    }

    public JPanel getCurPanel() {
        return curPanel;
    }
}
