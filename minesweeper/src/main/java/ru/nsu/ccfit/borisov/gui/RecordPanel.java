package ru.nsu.ccfit.borisov.gui;
import javax.swing.*;

import ru.nsu.ccfit.borisov.utilits.Pair;

import java.awt.*;

public class RecordPanel {
    RecordPanel(Pair[] recordTable) {
        JPanel myPanel = new JPanel();
        myPanel.setLayout(new GridLayout(0, 1));

        for (int i = 0; i < recordTable.length && recordTable[i].getSecond() != Pair.EMPTY; i++) {
            myPanel.add(new JLabel(i + ":  name:  \"" + recordTable[i].getFirst() + "\"  time:  " + String.format("%.3f", recordTable[i].getSecond())));
        }
        if (recordTable[0].getSecond() == Pair.EMPTY) myPanel.add(new JLabel("no records :("));


        JOptionPane.showConfirmDialog(null, myPanel,
                "RECORDS", JOptionPane.DEFAULT_OPTION);

    }
}
