Page {
    ListView {
        id: listview
        function itemType(data, indexPath){
            return (indexPath.length == 1 ? "MyHeader" : "MyItem" )
        }
        dataModel: GroupDataModel {
            id: people
            source: "people.xml"
        }
        onTriggered: {
            listview.clearSelection();
            toggleSelection(indexPath);        
        }
        listItemComponents: [
            
        ] 
    } // ListView
}// Page
