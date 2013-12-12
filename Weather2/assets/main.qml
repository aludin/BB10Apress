import bb.cascades 1.2
TabbedPane {
    showTabsOnActionBar: true
    Tab {
        title: "City weather"
        Page {
            ControlDelegate {
                delegateActive: true
                source: "weatherDetails.qml"
            }
        }
    }
    Tab {
        title: "Map"
        Page {
            ControlDelegate {
                delegateActive: true
                source: "weatherMap.qml"
            }
        }
    }
}
