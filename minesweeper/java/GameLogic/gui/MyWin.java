package minesweeper.java.GameLogic.gui;

import java.awt.*;
import javax.swing.*;

import minesweeper.java.GameLogic.GameLogic;
import minesweeper.java.GameLogic.exception.MinesweeperException;

public class MyWin extends JFrame {
    private final Context context;
    private final JPanel curPanel;

    public MyWin(GameLogic game) {

        JPanel standardPanel = new JPanel(new BorderLayout());
        add(standardPanel);
        context = new Context(game, this);
        curPanel = new GamePanel(context);
        standardPanel.add(curPanel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        double defaultWidth = dimension.width / 2.5;
        double defaultHeight = dimension.height / 2.5;
        setBounds((int) defaultWidth, (int) defaultHeight, (int) defaultWidth, (int) defaultHeight);
    }

    public void openSettings() throws MinesweeperException {
        new SettingsPanel(context);

    }

    public void showRecordTable() {
        new RecordPanel(context.getGame().getRecordsTable());
    }

    public JPanel getCurPanel() {
        return curPanel;
    }
}
