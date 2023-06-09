package minesweeper.java.Minesweeper.text;

import minesweeper.java.Minesweeper.Field;
import minesweeper.java.Minesweeper.Minesweeper;
import minesweeper.java.Minesweeper.exception.MinesweeperException;
import minesweeper.java.Minesweeper.exception.parcer.ParcerException;
import minesweeper.java.Minesweeper.exception.parcer.UnknownCommandException;
import minesweeper.java.Minesweeper.utilits.Command;
import minesweeper.java.Minesweeper.utilits.CommandParcer;
import minesweeper.java.Minesweeper.utilits.Pair;

import java.util.Scanner;

import static minesweeper.java.Minesweeper.utilits.CommandParcer.SPACE;

public class TextInterface {
    private DisplayedField displayedField;

    private static final String YES_ANSWER = "y";
    private static final String NO_ANSWER = "n";


    private Minesweeper game;
    public TextInterface() {
        this.game = new Minesweeper();
    }

    private void clickCase(Command cmd) throws MinesweeperException {
        int res = game.click(cmd.getArgs()[0], cmd.getArgs()[1]);
        displayedField.setCell(cmd.getArgs()[0], cmd.getArgs()[1], res);
        displayedField.print();
        if (res == Field.BOOM){
            System.out.println("You lose :(");
            displayedField  = new DisplayedField(game.getLinesLength(), game.getColumnsLength());
        } 
    }

    private void restartCase() throws MinesweeperException {
        game.restartGame();
        displayedField  = new DisplayedField(game.getLinesLength(), game.getColumnsLength());
        displayedField.print();
    }

    private void unFlagCase(Command cmd) throws MinesweeperException {
        game.unFlag(cmd.getArgs()[0], cmd.getArgs()[1]);
        displayedField.deleteFlag(cmd.getArgs()[0], cmd.getArgs()[1]);
        displayedField.print();
    }

    private void showRecordsCase() throws MinesweeperException {
        Pair[] recordsTable = game.getRecordsTable();

        for (int i = 0; i < recordsTable.length && recordsTable[i].getSecond() != Pair.EMPTY; i++) {
            System.out.print(i + ": name:    \""+ recordsTable[i].getFirst() + "\" time: " + recordsTable[i].getSecond()+"\n");
        }
        if (recordsTable[0].getSecond() == Pair.EMPTY)  System.out.print("no records :(\n");
    }

    private void flagCase(Command cmd, Scanner scanner) throws MinesweeperException {
        if (game.flag(cmd.getArgs()[0], cmd.getArgs()[1])) {
            System.out.print("YOU WON. Your time "+ game.getTime()+" seconds!!!\n");
            System.out.print("Do you want to save your record? ["+ YES_ANSWER+"/"+ NO_ANSWER +"]");
            String line = scanner.nextLine();
            String[] strSplit = line.split(SPACE);
            if (strSplit.length > 1)
                throw new ParcerException();
            if (strSplit[0].equals(YES_ANSWER)) {
                System.out.print("Enter your name:\n");
                line = scanner.nextLine();
                game.updateRecord(new Pair(line, game.getTime()));
            } else if (!strSplit[0].equals(NO_ANSWER)) {
                throw new UnknownCommandException(strSplit[0]);
            }

            displayedField = new DisplayedField(game.getLinesLength(), game.getColumnsLength());
        } else {
            displayedField.setFlag(cmd.getArgs()[0], cmd.getArgs()[1]);
            displayedField.print();
        }

    }

    public void startGame() {
        Scanner scanner = new Scanner(System.in);
        displayedField = new DisplayedField(game.getLinesLength(), game.getColumnsLength());
        while (true) {
            try {

                String line = scanner.nextLine();
                if (line.length() == 0) continue;
                Command cmd = CommandParcer.parsCommandLine(line);
        
                switch (cmd.getId()) {
                    case CLICK -> {
                        clickCase(cmd);
                    }
                    case SET_SETTINGS -> {
                        game.changeSettings(cmd.getArgs()[0], cmd.getArgs()[1], cmd.getArgs()[2]);
                        displayedField = new DisplayedField(game.getLinesLength(), game.getColumnsLength());
                    }
                    case RESTART -> {
                        restartCase();
                    }
                    case FLAG -> {
                        flagCase(cmd, scanner);
                    }
                    case UNFLAG -> {
                        unFlagCase(cmd);
                    } case SHOW_RECORDS -> {
                        showRecordsCase();
                    }
                    case EXIT -> {
                        return;
                    }
                }
            } catch (Exception e) {
                System.err.print(e.getMessage());
            }
        }

    }
}