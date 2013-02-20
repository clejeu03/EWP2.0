#include "ProjectManager.h"

#include <QDebug>

ProjectManager::ProjectManager()
{
    m_maxRecentProjects = 3;

    /*TO DO : parseur XML pour le fichier de sauvagerde d'état du logiciel
     * en cas d'interruption violente du travail
     * doit remplir la liste de fichiers récents et la liste de fichiers ouverts*/
    if(!m_openProjects.empty()){
        for(int i=0; i<m_openProjects.size();++i){
            openProject(m_openProjects[i]);
        }
    }
}

/*Create a personnalized project with customs name and path*/
Project* ProjectManager::newProject(QString path, QString name){
    Project *project = new Project(name, path);
    m_openProjects.append(project->getProjectCompletePath());
    m_recentProjects.append(project->getProjectCompletePath());
    return project;
}

/*Open a file with the .ewp extension*/
void ProjectManager::openProject(QString projectPath){
    if(m_openProjects.size()<5){//Fixed max open projects at the same time
        QFileInfo info(projectPath);
        if(info.exists()){
            if(info.completeSuffix()==".ewp"){
                Project *project = new Project(projectPath, info.completeBaseName());
                m_openProjects.append(project->getProjectCompletePath());
                m_recentProjects.append(project->getProjectCompletePath());

                /*TO DO :
                 *parseur XML pour lire la liste de chemin de vidéo du fichier
                 *et faire project->import(path)
                 *et mettre à jour ensuite les propriétés d'état de la vidéo en y accédant par le projet*/

            }else{
                qDebug() << "EWP-Error :  is not a .ewp file." ;
            }
        }else{
            qDebug() << "EWP-Error : " << projectPath << " is not a valid path." ;
        }
    }else{
        qDebug() << "EWP-Error : you can't open a new project." ;
    }
}

/*Save a project in the name.ewp file into the path dir*/
bool ProjectManager::saveProject(Project project){
     if(m_openProjects.contains(project.getProjectCompletePath())){
        /*TO DO :
         *générateur XML pour enregistrer tous les params
         *et message d'erreur si échec*/
         return true;
     }else{
         return false;
     }
}

/*Save a project from the path in the name.ewp file into the path dir*/
bool ProjectManager::saveProject(QString projectPath){
     if(m_openProjects.contains(projectPath)){
        /*TO DO :
         *générateur XML pour enregistrer tous les params
         *et message d'erreur si échec*/
         return true;
     }else{
         return false;
     }
}

/*Save all the open projects*/
bool ProjectManager::saveAllProjects(){
    for(int i = 0; i< m_openProjects.size(); ++i){
        if(!saveProject(m_openProjects[i])){
            return false;
        }
    }
    return true;
}

/*Close a project and save him before*/
void ProjectManager::closeProject(Project *project){
    if(m_openProjects.contains(project->getProjectCompletePath())){
        if(saveProject(*project)){
            m_openProjects.removeOne(project->getProjectCompletePath());
            delete(project);
        }else{
            qDebug() << "EWP-Error : an error occurs in saving the current project." ;
        }
     }else{
        qDebug() << "EWP-Error : this project does not exists." ;
    }
}

/*Close all the open projects and save them before*/
void ProjectManager::closeAllProjects(){
    if(saveAllProjects()){
        m_openProjects.clear();
    }else{
        qDebug() << "EWP-Error : an error occurs in saving the current projects." ;
    }
}

/*Handle the recentProject list management.*/
void ProjectManager::addToRecentProject(Project project){
    if(m_recentProjects.size() < m_maxRecentProjects-1){
        m_recentProjects.append(project.getProjectCompletePath());
    }else{
        m_recentProjects.removeFirst();
        for(int i=1; i<m_maxRecentProjects; ++i){
            m_recentProjects.move(i, i-1);
        }
        m_recentProjects.append(project.getProjectCompletePath());
    }
}