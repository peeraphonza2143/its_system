window.onload=function ()
{
    showData();
}
  function showData()
{
  
  
  var Position1=firebase.database().ref("Floor3/Position1/MAN/Room1");
  var Position2=firebase.database().ref("Floor3/Position1/MAN/Room2");


  Position1.once('value').then(function(dataSnapshot1){
  document.getElementById("P1MRoom1").innerHTML = dataSnapshot1.val();
  });
  Position2.once('value').then(function(dataSnapshot2){
  document.getElementById("P1MRoom2").innerHTML = dataSnapshot2.val();
  });

}
function ReadColour()
{
  if(Position1==1)
  {
    
  }
  else
  {

  }
}