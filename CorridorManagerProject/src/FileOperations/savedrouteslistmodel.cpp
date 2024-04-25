#include "savedrouteslistmodel.h"
#include <QDebug>

SavedRoutesListModel::SavedRoutesListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int SavedRoutesListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_savedRoutes.count();
}

QVariant SavedRoutesListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const RouteQuickData route = m_savedRoutes[index.row()];
    switch (role) {
    case RouteName:
        return route.m_routeName;
    case RouteDistance:
        return route.m_routeDistance;
    case WayPointCount:
        return route.m_wayPointCount;
    default:
        return QVariant();
    }
}

void SavedRoutesListModel::loadRouteList(const QList<RouteQuickData> savedRoutes)
{
    beginResetModel();
    m_savedRoutes = savedRoutes;
    endResetModel();
}

QHash<int, QByteArray> SavedRoutesListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RouteName] = "name";
    roles[RouteDistance] = "distance";
    roles[WayPointCount] = "waypointcount";
    return roles;
}
