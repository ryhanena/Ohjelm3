#ifndef RESOURCELIST_HH
#define RESOURCELIST_HH

#include <QDialog>

namespace Ui {
class ResourceList;
}
/**
 * @brief The ResourceList class
 */
class ResourceList : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief ResourceList
     * @param parent
     */
    explicit ResourceList(QWidget *parent = 0);
    ~ResourceList();

private slots:
    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:
    Ui::ResourceList *ui;
};

#endif // RESOURCELIST_HH
