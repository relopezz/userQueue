<?php

include 'class.Queue.inc';
$users = new userQueue();

//Adding 1 to 6 users
for($i = 1; $i <= 6; $i++) {
    $users->add($i);
}
echo '<pre> ADDING USERS'; print_r($users);

//Remove user
$user = $users->removeUsers(2);
echo '<pre> REMOVE USER 2'; print_r($users);

//Remove user
$user = $users->removeUsers(6);
echo '<pre> REMOVE USER 6'; print_r($users);

//Remove by Position
//$user = $users->removeByPosition(1);
//echo '<pre> REMOVE POSITION 1 -- !'; print_r($users);

//MOVE 3,1 Guessing is move user 3 to the user 1 position

//REVERSE
$users_reverse = $users->reverseQ();
echo '<pre> REVERSE QUEUE'; print_r($users_reverse);