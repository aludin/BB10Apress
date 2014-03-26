import bb.cascades 1.2
TabbedPane {
    id: tabbedPane
    showTabsOnActionBar: true
    Tab {
        title: "City weather"
        Page {
            WeatherDetails {

            }
        }
    }
    Tab {
        title: "Map"
        Page {
            WeatherMap {

            }
        }
    }
}
