import bb.cascades 1.2
NavigationPane {
    backButtonsVisible: true
    peekEnabled: true
    Page {
        titleBar: TitleBar {
            title: "RiskCetera Previewer Card"
        }
        Container {
            layout: DockLayout {
                
            }
            ImageView {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                imageSource: _app.uri
                scalingMethod: ScalingMethod.AspectFit
            }
        }
    }
}
