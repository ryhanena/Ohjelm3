#ifndef ENDDIALOG_HH
#define ENDDIALOG_HH

#include <QDialog>
#include <map>
#include <string>

#include "player.hh"

namespace Ui {
class EndDialog;
}
namespace student {


/**
 * @brief The EndDialog class manages the dialog at the end
 *
 * Calculates players resources and checks the winner
 */
class EndDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief EndDialog constructor
     * @param parent
     */
    explicit EndDialog(QWidget *parent = 0);

    ~EndDialog();

    /**
     * @brief calculatePoints calculates player points and
     * saves data to pointsMap_
     * @param player
     */
    void calculatePoints(std::shared_ptr<student::Player> player);

    /**
     * @brief getPlayers receive vector of players who survived through
     * the game and uses other functions in this class
     * @param player vector
     */
    void getPlayers(std::vector<std::shared_ptr<student::Player>> player);

    /**
     * @brief showResults manages the graphics of end dialog
     */
    void showResults();

    /**
     * @brief getWinner calulates the winner of the game and
     * saves it to winner_ pair
     */
    void getWinner();

private:
    std::map<std::string, unsigned int> pointsMap_;
    std::pair<std::string, unsigned int> winner_;
    Ui::EndDialog *ui;
};
}

#endif // ENDDIALOG_HH
