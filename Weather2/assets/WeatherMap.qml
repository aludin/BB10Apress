import bb.cascades 1.2
import ludin.utils 1.0
Container {
    layout: DockLayout {
    }
    
    onCreationCompleted: {
        _app.weather.cityinfo.coordinatesChanged.connect(mapclient.setCoordinates);
        scrollview.zoomToPoint(320, 220, 2, ScrollAnimation.Smooth);
    }
    attachedObjects: [
        GoogleMapClient {
            id: mapclient
        }
    ]
    ScrollView {
        id: scrollview
        horizontalAlignment: HorizontalAlignment.Fill
        verticalAlignment: VerticalAlignment.Fill
        scrollViewProperties {
            scrollMode: ScrollMode.Both
            pinchToZoomEnabled: true
        }
        ImageView {
            id: citymap
            image: mapclient.image
        }
       
    }
}
