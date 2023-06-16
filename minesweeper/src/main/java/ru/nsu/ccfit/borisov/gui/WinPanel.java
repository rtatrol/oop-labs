package ru.nsu.ccfit.borisov.gui;

import javax.swing.*;

import ru.nsu.ccfit.borisov.utilits.Pair;

import java.awt.*;

public class WinPanel {

    private static final int FIELD_WIDTH = 10;

    public static void winPanel(Context context) {
        JPanel myPanel = new JPanel();
        myPanel.setLayout(new GridLayout(0, 1));
        myPanel.add(
                new JLabel("YOU WIN. You time: " + String.format("%.3f", context.getGame().getTime()) + " seconds!!!"));
        myPanel.add(new JLabel("Enter your name:"));
        JTextField field = new JTextField(FIELD_WIDTH);
        myPanel.add(field);

        int result = JOptionPane.showConfirmDialog(null, myPanel,
                "RECORDS", JOptionPane.OK_CANCEL_OPTION);

        if (result == JOptionPane.OK_OPTION) {
            context.getGame().updateRecord(new Pair(field.getText(), context.getGame().getTime()));
        }
    }
}