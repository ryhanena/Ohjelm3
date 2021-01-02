#ifndef GAMEDIALOG_HH
#define GAMEDIALOG_HH

#include <QDialog>

namespace Ui {
class gameDialog;
}

/**
 * @brief The gameDialog class represents start dialog
 *
 * Set in MapWindow
 */

class gameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gameDialog(QWidget *parent = 0);
    ~gameDialog();

signals:
    /**
     * @brief sendData sends data to MapWindow
     * @param size size of map (size * size)
     * @param scale of tile
     */
    void sendData(int size, int scale, int rounds);
    /**
     * @brief setPlayerCount sends amount of players in game
     * @param count
     */
    void setPlayerCount(int count);

private slots:

    /**
     * @brief on_pushButton_clicked starts the game
     */
    void on_pushButton_clicked();
    /**
     * @brief on_setScale_valueChanged set scale if it's changed
     * @param arg1
     */
    void on_setScale_valueChanged(int arg1);
    /**
     * @brief on_MapSize_valueChanged set map size if it's changed
     * @param arg1
     */
    void on_MapSize_valueChanged(int arg1);
    /**
     * @brief on_Players_valueChanged set amount of players if it's changed
     * @param arg1
     */
    void on_Players_valueChanged(int arg1);

    void on_setRounds_valueChanged(int arg1);

private:
    Ui::gameDialog *ui;
    int mapSize_;
    int scale_;
    int playerCount_;
    int rounds_;
};

#endif // GAMEDIALOG_HH
