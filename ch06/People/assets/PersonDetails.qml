import bb.cascades 1.0

Page {
    property variant person;
    Container {
        verticalAlignment: VerticalAlignment.Center
        horizontalAlignment: HorizontalAlignment.Center
        topPadding: 50
        ImageView {
            horizontalAlignment: HorizontalAlignment.Center
            imageSource: "asset:///pics/"+person.pic
            preferredWidth: 400
            preferredHeight: 400
        }
        Label {
            textStyle.base: SystemDefaults.TextStyles.BigText
            horizontalAlignment: HorizontalAlignment.Center
         	text: person.name   
        }
        Label {
            textStyle.base: SystemDefaults.TextStyles.SubtitleText
            horizontalAlignment: HorizontalAlignment.Center
            text: "date of birth: "+person.born   
        }
    }
}
