#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <QWidget>

class QPushButton;

class TicTacToeGame : public QWidget
{
    Q_OBJECT

public:
    explicit TicTacToeGame(QWidget *parent = nullptr);

private slots:
    void handleButton();

private:
    void checkForWin();

    enum Player {
        None,
        Player1,
        Player2
    };

    Player m_currentPlayer;
    QList<QPushButton*> m_buttons;
    QIcon m_iconCross;
    QIcon m_iconZero;
};

#endif // TICTACTOEGAME_H
