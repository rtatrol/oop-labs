package ru.nsu.ccfit.borisov;

import ru.nsu.ccfit.borisov.config.Configuration;
import ru.nsu.ccfit.borisov.exception.field.CantOpenFlagException;
import ru.nsu.ccfit.borisov.exception.field.FieldException;
import ru.nsu.ccfit.borisov.exception.field.IndexOutOfBoundException;
import ru.nsu.ccfit.borisov.exception.game.GameLogicException;

public class Field {


    private Configuration configuration;
    private boolean[][] fieldIsMine;
    private boolean[][] fieldIsOpen;
    private boolean[][] fieldIsFlag;

    private int unFlaggedMines;

    private int usedFlags;

    public int getUsedFlags() {
        return usedFlags;
    }

    public Configuration getConfiguration() {
        return configuration;
    }


    public static final int BOOM = -1;
    public static final int[] xMoves = new int[]{-1, 0, 1};
    public static final int[] yMoves = new int[]{-1, 0, 1};

    public Field(Configuration conf, int ignoredX, int ignoredY) {
        configuration = conf;
        int N = conf.getColumnLength();
        int M = conf.getLineLength();
        int minesNumber = conf.getMinesNumber();
        unFlaggedMines = minesNumber;
        fieldIsFlag = new boolean[N][M];
        fieldIsOpen = new boolean[N][M];
        fieldIsMine = new boolean[N][M];


        double p = (minesNumber * 1.0) / (N * M * 2.5);
        int minesCounter = 0;
        for (int i = 0; minesCounter < minesNumber; i = (i + 1) % N) {
            for (int j = 0; minesCounter < minesNumber && j < M; j++) {
                if (fieldIsMine[i][j] || (i == ignoredX && j == ignoredY)) continue;
                if (Math.random() <= p) {
                    fieldIsMine[i][j] = true;
                    minesCounter++;
                }
            }
        }
    }
    
    public boolean correctXY(int x, int y) {
        int M = configuration.getLineLength();
        int N = configuration.getColumnLength();
        return !(x >= N || y >= M || x < 0 || y < 0);
    }

    public boolean[][] getMines() {
        return fieldIsMine;
    }

    public boolean isOpen(int x, int y) {
        return fieldIsOpen[x][y];
    }


    public int openCell(int x, int y) throws FieldException {
        if(!correctXY(x, y)) throw new IndexOutOfBoundException(x, y, configuration);

        if (fieldIsFlag[x][y]) throw new CantOpenFlagException(x, y);
        if (fieldIsMine[x][y]) return BOOM;
        fieldIsOpen[x][y] = true;
        int minesCounter = 0;
        for (int xMove : xMoves) {
            for (int yMove : yMoves) {
                if (!correctXY(x + xMove, y + yMove)) continue;
                if (fieldIsMine[x + xMove][y + yMove]) minesCounter++;
            }
        }
        return minesCounter;
    }

    public int flag(int  x, int y) throws FieldException, GameLogicException {
        if(!correctXY(x, y)) throw new IndexOutOfBoundException(x, y, configuration);
        if (fieldIsOpen[x][y]) throw new GameLogicException("you can't flag open cell");
        if (fieldIsFlag[x][y]){
            return unFlaggedMines;
        }
        fieldIsFlag[x][y] = true;
        if (fieldIsMine[x][y]) unFlaggedMines -= 1;
        usedFlags += 1;
        return unFlaggedMines;
    }

    public int unflag(int  x, int y) throws FieldException, GameLogicException {
        if(!correctXY(x, y)) throw new IndexOutOfBoundException(x, y, configuration);
        if (!fieldIsFlag[x][y]) throw new GameLogicException("you can't un flag un flagged cell");
        fieldIsFlag[x][y] = false;
        if (fieldIsMine[x][y]) unFlaggedMines += 1;
        usedFlags -= 1;
        return unFlaggedMines;
    }

}