#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>

#include "Project.h"
//#include "Visible.h"


class ProjectManager /*: virtual public Visible*/ {

 public:
    ProjectManager();
    Project* newProject(QString path, QString name = "untitled");
    void recentProjects();
    void openProject(QString projectPath);
    bool saveProject(Project project);
    bool saveProject(QString projectPath);
    bool saveAllProjects();
    void closeProject(Project *project);
    void closeAllProjects();
    void addToRecentProject(Project project);

    inline QList<QString> getOpenProjectsList(){return m_openProjects;}
    inline int getMaxRecentProjects(){return m_maxRecentProjects;}
    inline void setMaxRecentProjects(int max){m_maxRecentProjects = max;}

 private:
    QString m_defaultPath;
    int m_maxRecentProjects;
    QList<QString> m_openProjects; //Store the paths
    QList<QString> m_recentProjects; //Store the paths
    //Visible &myVisible;
};


#endif // PROJECTMANAGER_H
