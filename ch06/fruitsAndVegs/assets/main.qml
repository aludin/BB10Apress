import bb.cascades 1.2
import bb.data 1.0
Page {
    Container {
        ListView {
            id: listview
            objectName: "listview"
            dataModel: GroupDataModel {
                id: groupDataModel
            }
            function itemType(data, indexPath) {
                return (indexPath.length == 1 ? "myheader" : "myitem");
            }
            listItemComponents: [
                ListItemComponent {
                    type: "myheader"
                    CustomListItem {
                        dividerVisible: true
                        Label {
                            text: ListItemData
                            textStyle {
                                base: SystemDefaults.TextStyles.BigText
                                fontWeight: FontWeight.Bold
                                color: Color.create("#7a184a")
                            }
                        }
                    }
                },
                ListItemComponent {
                    type: "myitem"
                   /* 
                     StandardListItem {
                     id: standardListItem
                     title: ListItemData.name
                     description: ListItemData.description
                     status: "Good for you!"
                     
                     }*/
                    
                    CustomListItem {
                        id: customItem
                        Container {
                            verticalAlignment: VerticalAlignment.Center
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            CheckBox {
                                id: checkBox
                                checked: ListItemData.available
                                onCheckedChanged: {
                                    if (customItem.ListItem.initialized) {
                                        var index = customItem.ListItem.indexPath;
                                        console.log("Changing " + index);
                                        var dataModel = customItem.ListItem.view.dataModel;
                                        var val = dataModel.data(index);
                                        val.available = checked;
                                        dataModel.updateItem(index, val);
                                        console.log("after update: " + dataModel.data(index).name + ", available: " + dataModel.data(index).available);
                                    }
                                }
                            }
                            Label {
                                text: ListItemData.name
                            }
                        }
                    }
                }
            ]
        }
        attachedObjects: [
            DataSource {
                id: dataSource
                source: "asset:///fruitsandvegetables.json"
                onDataLoaded: {
                    for (var i = 0; i < data.length; i ++) {
                        groupDataModel.insert(data[i]);
                    }
                }
            }
        ]
        onCreationCompleted: {
            dataSource.load();
            groupDataModel.sortingKeys = [ "name", "description" ];
        }
    }
}
