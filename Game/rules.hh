#ifndef RULES_HH
#define RULES_HH

#include <QDialog>

namespace Ui {
class Rules;
}
/**
 * @brief The Rules class
 */
class Rules : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Rules
     * @param parent
     */
    explicit Rules(QWidget *parent = 0);
    ~Rules();

private slots:
    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:
    Ui::Rules *ui;

};

#endif // RULES_HH
