package minesweeper.java.Minesweeper.gui.button;

import minesweeper.java.Minesweeper.exception.MinesweeperException;
import minesweeper.java.Minesweeper.gui.Context;
import minesweeper.java.Minesweeper.gui.GamePanel;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MenuButtonsListener implements ActionListener {
    Context context;

    public MenuButtonsListener(Context context) {
        this.context = context;
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        try {
            switch (((MenuButtons) e.getSource()).getType()) {
                case FLAG -> context.setClick(!context.isClick());
                case RESTART -> {
                    context.getGame().restartGame();
                    context.setNeedToRestart(false);
                    ((GamePanel) context.getWin().getCurPanel()).updatePanel();
                }
                case SETTINGS -> context.getWin().openSettings();
                case RECORD_TABLE -> context.getWin().showRecordTable();
            }
        } catch (MinesweeperException exception) {
            JOptionPane.showMessageDialog(null, exception.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
        }

    }
}