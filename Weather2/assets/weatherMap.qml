import bb.cascades 1.2

ScrollView {
    id: scrollview
    objectName: "scrollview"
    scrollViewProperties {
        scrollMode: ScrollMode.Both
        pinchToZoomEnabled: true
    }
    ImageView {
        id: citymap
        verticalAlignment: VerticalAlignment.Center
        horizontalAlignment: HorizontalAlignment.Center
        objectName: "citymap"
    }
    onCreationCompleted: {
        scrollview.zoomToPoint(320, 220, 2, ScrollAnimation.Smooth);
    }
}
