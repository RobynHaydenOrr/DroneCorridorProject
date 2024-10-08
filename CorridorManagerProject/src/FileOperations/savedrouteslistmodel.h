#ifndef SAVEDROUTESLISTMODEL_H
#define SAVEDROUTESLISTMODEL_H

#include <QAbstractListModel>

class SavedRoutesListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int routeNameRole READ routeNameRole CONSTANT)
    Q_PROPERTY(int totalDistanceRole READ totalDistanceRole CONSTANT)
    Q_PROPERTY(int wayPointCountRole READ wayPointCountRole CONSTANT)
    Q_PROPERTY(bool approved READ approved CONSTANT)

public:
    /**
     * @brief Enum for Route Quick Data roles.
     */
    enum RouteRoles {
        RouteName = Qt::UserRole + 1,
        RouteDistance,
        WayPointCount,
        Approved
    };

    static int routeNameRole() { return RouteName; }
    static int totalDistanceRole() { return RouteDistance; }
    static int wayPointCountRole() { return WayPointCount; }
    static bool approved() { return Approved; }

    /**
     * @brief Struct to hold Route Quick Data.
     */
    struct RouteQuickData {
        QString m_routeName;
        double m_routeDistance;
        int m_wayPointCount;
        bool m_approved;

        /**
         * @brief Constructor for RouteQuickData.
         * @param routeName Name for route.
         * @param droneName Name of drone for route.
         * @param routeDistance Total travel distance for route.
         * @param routeTime Total travel time for route.
         */
        RouteQuickData( const QString & routeName, const QString & droneName,
                       const double routeDistance, const double routeTime,
                       const int wayPointCount, const bool approved )
        {
            m_routeName = routeName;
            m_routeDistance = routeDistance;
            m_wayPointCount = wayPointCount;
            m_approved = approved;
        }

    };

    /**
     * @brief Constructor for SavedRoutesListModel.
     * @param parent The parent QObject.
     */
    explicit SavedRoutesListModel(QObject *parent = nullptr);

    /**
     * @brief Returns the number of rows in the model.
     * @param parent The parent index.
     * @return The number of saved routes.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief Retrieves data from the model.
     * @param index The index of the item.
     * @param role The role for which data is required.
     * @return The data stored under the given role for the item referred to by the index.
     */
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * @brief Loads cached data with pre-populated route list.
     * @param savedRoutes QList of RouteQuickData.
     */
    void loadRouteList( const QList< RouteQuickData > savedRoutes );

    /**
     * @brief Provides the role names to be used in QML.
     * @return A hash table of role names.
     */
    QHash<int, QByteArray> roleNames() const override;

    /**
     * @brief Refreshes model.
     **/
    void refresh();
signals:
    /**
     * @brief Signal indidcated data model changed.
     */
    void savedRoutesChanged();

private:
    QList< RouteQuickData > m_savedRoutes;
};

#endif // SAVEDROUTESLISTMODEL_H
