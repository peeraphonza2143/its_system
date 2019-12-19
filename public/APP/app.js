window.onload=function ()
{
    //showData();
     ReadColour();
}
 /* function showData()
{
  
  
  var Position1=firebase.database().ref("Floor3/Position1/MAN/Room1");
  var Position2=firebase.database().ref("Floor3/Position1/MAN/Room2");


  Position1.once('value').then(function(dataSnapshot1){
  document.getElementById("P1MRoom1").innerHTML = dataSnapshot1.val();
  });
  Position2.once('value').then(function(dataSnapshot2){
  document.getElementById("P1MRoom2").innerHTML = dataSnapshot2.val();
  });

}*/
/*function ReadColour()
{
   var Position1=firebase.database().ref("Floor3/Position1/MAN/Room1");
    if(Position1==0)
    {
     document.getElementById("P1MRoom1").src="INMAGE/A2.jpg";
    }
    else 
    {
      document.getElementById("P1MRoom1").src="INMAGE/A2.jpg";
    }             
}*/
function  ReadColour()
{
var data0 = firebase.database().ref().child("Floor3/Position1/Woman/Room1");
var data1 = firebase.database().ref().child("Floor3/Position1/Woman/Room2");
var data2 = firebase.database().ref().child("Floor3/Position1/Woman/Room3"); 
var data3 = firebase.database().ref().child("Floor3/Position1/MAN/Room1");
var data4 = firebase.database().ref().child("Floor3/Position1/MAN/Room2");
var data5 = firebase.database().ref().child("Floor3/Position1/MAN/Room3");     
          data0.on("value", function(snap){
            switch(snap.val()){
                 case 1:
                     document.getElementById("P1FMRoom1").src="INMAGE/A3.jpg";
                 break;
                 case 0:
                     document.getElementById("P1FMRoom1").src="INMAGE/A2.jpg";
                 break;
            }
           });

           data1.on("value", function(snap){
            switch(snap.val()){
                 case 1:
                     document.getElementById("P1FMRoom2").src="INMAGE/A3.jpg";
                 break;
                 case 0:
                     document.getElementById("P1FMRoom2").src="INMAGE/A2.jpg";
                 break;
            }
           });

           data2.on("value", function(snap){
            switch(snap.val()){
                 case 1:
                     document.getElementById("P1FMRoom3").src="INMAGE/A3.jpg";
                 break;
                 case 0:
                     document.getElementById("P1FMRoom3").src="INMAGE/A2.jpg";
                 break;
            }
           });
           data3.on("value", function(snap){
            switch(snap.val()){
                 case 1:
                     document.getElementById("P1MRoom1").src="INMAGE/B3.jpg";
                 break;
                 case 0:
                     document.getElementById("P1MRoom1").src="INMAGE/B2.jpg";
                 break;
            }
           });
           data4.on("value", function(snap){
            switch(snap.val()){
                 case 1:
                     document.getElementById("P1MRoom2").src="INMAGE/B3.jpg";
                 break;
                 case 0:
                     document.getElementById("P1MRoom2").src="INMAGE/B2.jpg";
                 break;
            }
           });
           data5.on("value", function(snap){
            switch(snap.val()){
                 case 1:
                     document.getElementById("P1MRoom3").src="INMAGE/B3.jpg";
                 break;
                 case 0:
                     document.getElementById("P1MRoom3").src="INMAGE/B2.jpg";
                 break;
            }
           });
}