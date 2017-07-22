#ifndef NODE_H
#define NODE_H

#include <QtCore/qglobal.h>

/**
 * @brief The Node class
 */
class Node
{
public:
    explicit Node();

//Getters
    QString getBlockchain();
    QString getServer();
    QString getPort();

// Setters
    void setBlockchain(QString &blockchain);
    void setServer(QString *mysqever);
    void setPort(QString *myport);
    void setRpcUser(QString myuser);
    void setRpcPassword(QString mypassword);

private:

    QString *chain;
    QString *server;
    QString *port;

};

//typedef struct mc_OneMultichainParam
//{
//    char m_Name[MC_PRM_MAX_ARG_NAME_SIZE+1];
//    char m_DisplayName[MC_PRM_MAX_ARG_NAME_SIZE+1];
//    int m_Type;
//    int m_MaxStringSize;
//    int64_t m_DefaultIntegerValue;
//    int64_t m_MinIntegerValue;
//    int64_t m_MaxIntegerValue;
//    double m_DefaultDoubleValue;
//    int m_ProtocolVersion;
//    int m_Removed;
//    char m_ArgName[MC_PRM_MAX_PARAM_NAME_SIZE+1];
//    char m_Next[MC_PRM_MAX_ARG_NAME_SIZE+1];
//    char m_Group[MC_PRM_MAX_DESCRIPTION_SIZE+1];
//    char m_Description[MC_PRM_MAX_DESCRIPTION_SIZE+1];

//    int IsRelevant(int version);
//} mc_OneMultichainParam;

#endif // NODE_H
