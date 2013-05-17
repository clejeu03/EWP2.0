#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>
#include <QMessageBox>

#include "Project.h"
//#include "Visible.h"


class ProjectManager /*: virtual public Visible*/ {

 public:
    ProjectManager();
    Project* newProject(QString path, QString name = "untitled");
    void recentProjects();
    Project* openProject(QString projectPath);
    bool saveProject(Project project);
    bool saveProject(QString projectPath, QString &projectName, QString workspace);
    bool saveAllProjects();
    void closeProject(Project *project);
    void closeAllProjects();
    void addToRecentProject(Project project);

    inline QList<QString> getOpenProjectsList(){return m_openProjectsPath;}
    inline int getMaxRecentProjects(){return m_maxRecentProjects;}
    inline void setMaxRecentProjects(int max){m_maxRecentProjects = max;}
    inline QList<Project*> getProjects(){return m_projectList;}
    inline int getProjectListSize(){return m_openProjectsPath.length();}

 private:
    QString m_defaultPath;
    int m_maxRecentProjects;
    QList<QString> m_openProjectsPath; //Store the paths
    QList<QString> m_recentProjects; //Store the paths
    QList<Project*> m_projectList; //Store the references to projects
    //Visible &myVisible;
};


#endif // PROJECTMANAGER_H
