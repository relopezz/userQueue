<?php
include 'class.Queue.inc'

$users = new userQueue();



// Tester Section

//Create new user queue
$users = new userQueue();

//Actions Section

/*
ACTION 1
ADD,1
ADD,2
ADD,3
ADD,4
ADD,5
ADD,6
*/

//Ading a single user
$new_user= $users->add(1);
echo /* Action 1 */ __FILE__ . ':'. __LINE__ . '<pre> *** Adding a single user ***<br />'; 
echo 'User Position:  '.$new_user. '<br />';

echo "---   Queue:   ---  <br />";
print_r($users);

//Adding 2 to 6 users

for($i = 2; $i <= 6; $i++) {
	$new_user = $users->add($i);
	echo 'User Position:  '.$new_user. '<br />';
}
echo /* Action 1.2 */ __FILE__ . ':'. __LINE__ . '<pre> *** Adding the rest users ***<br />'; 
print_r($users);

//Remove user 2
$user = $users->removeByUser(2);
echo /* Action 2 */ __FILE__ . ':'. __LINE__ . '<pre> *** Remove User 2 ***<br />'; 
print_r($user).'<br />';

echo "---   Queue:   ---  <br />";
print_r($users).'<br />';

//Remove user 6
$user = $users->removeByUser(6);
echo /* Action 3 */ __FILE__ . ':'. __LINE__ . '<pre> *** Remove User 6 ***<br />'; 
print_r($user).'<br />';

echo "---   Queue:   ---  <br />";
print_r($users).'<br />';


//REMOVE_USER,10
$user = $users->removeByUser(10);
echo /* Action 4 */ __FILE__ . ':'. __LINE__ . '<pre> *** Remove User 10 ***<br />'; 
print_r($user);

echo "---   Queue:   ---  <br />";
print_r($users).'<br />';


//MOVE,3,1
$user = $users->move(3,1);
echo /* Action 5 */ __FILE__ . ':'. __LINE__ . '<pre> *** Move 3 to 1 ***<br />'; 
print_r($user);

echo "---   Queue:   ---  <br />";
print_r($users).'<br />';


//REVERSE
$users = $users->reverse();
echo /* Action 6 */ __FILE__ . ':'. __LINE__ . '<pre> *** REVERSE ***<br />'; 
print_r($users);


//SWAP 6,1
$swap = $users->swap(6,1);
echo /* Action 7 */ __FILE__ . ':'. __LINE__ . '<pre> *** SWAP 6,1 ***<br />'; 
print_r($swap);
echo "---   Queue:   ---  <br />";
print_r($users).'<br />';


//Remove Position 3
//I will -1 here, because I'm reusing removeByPostion in removeByUser'
$position = 3;
$user = $users->removeByPosition($position-1);
echo /* Action 8 */ __FILE__ . ':'. __LINE__ . '<pre> *** Remove Position 3 ***<br />'; 
print_r($user);
echo "---   Queue:   ---  <br />";
print_r($users).'<br />';

//REMOVE_USER,1
$user = $users->removeByUser(1);
echo /* Action 9 */ __FILE__ . ':'. __LINE__ . '<pre> *** Remove User 1 ***<br />'; 
print_r($user);


echo "---   Queue:   ---  <br />";
print_r($users).'<br />';


//REMOVE_POSITION,6
//I will -1 here, because I'm reusing removeByPostion in removeByUser'
$position = 6;
$user = $users->removeByPosition($position-1);
echo /* Action 8 */ __FILE__ . ':'. __LINE__ . '<pre> *** Remove Position 6 ***<br />'; 
print_r($user);
echo "---   Queue:   ---  <br />";
print_r($users).'<br />';


//ADD,7
//ADD,8 PRINT
//Ading a single user
$new_user= $users->add(7);
echo /* Action 9 */ __FILE__ . ':'. __LINE__ . '<pre> *** Adding User 7 ***<br />'; 
echo 'User Position:  '.$new_user. '<br />';

echo "---   Queue:   ---  <br />";
print_r($users);

//Ading a single user
$new_user= $users->add(8);
echo /* Action 10 */ __FILE__ . ':'. __LINE__ . '<pre> *** Adding User 8 ***<br />'; 
echo 'User Position:  '.$new_user. '<br />';

echo "---   Queue:   ---  <br />";
print_r($users);

//PRINT
echo /* Action 10 */ __FILE__ . ':'. __LINE__ . '<pre> *** Adding User 8 ***<br />'; 
echo $users->printPrettyQueue();
//echo '<pre> REVERSE QUEUE'; $users_reverse;



