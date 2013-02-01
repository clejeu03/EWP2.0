#include "editor.h"

Editor::Editor(QObject *parent) :
    QObject(parent)
{
}

Editor::Editor(QString filepath, int value1, int value2, QObject *parent = 0){
    m_filepath = filepath;
    m_in = value1;
    m_out = value2;


}
