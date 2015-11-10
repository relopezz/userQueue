<?php
class userQueue {

	private $_queue = array();

	public function pop() {
		return array_pop($this->_queue);
	}

	public function queueIsEmpty() {
		return empty($this->_queue);
	}
	
    //Utils
	public function size() {
		return count($this->_queue);
	}

	public function front() { //front
		return end($this->_queue);
	}

	public function reset() { //reset
		return reset($this->_queue);
	}

	//Task
	public function add($value = NULL) {
		if ($value == NULL) {
			return "Please select a value";
		}
		array_unshift($this->_queue, $value);
	}
	
	public function removeByPosition($position) {
		if (!isset($this->_queue[$position])) {
			return "Please select a valid position";
		}
		unset($this->_queue[$position]);
		$this->_queue = array_values($this->_queue);
	}
	
	public function reverse() {
		$this->_queue = array_reverse($this->_queue);
		return $this;
	}
	
	public function removeByUser($user){
		$index = array_search($user, $this->_queue);
		if ( $index !== false ) {
			$this->removeByPosition($index);
		} else {
			return "Please select a value user";
		}
	}
	
	//FIX
	public function move($from_position, $to_position) {
		
		if(!isset($this->_queue[$from_position])) {
			return "The position selected does not exists";
		}
		
		$temp_queue = [];
		$element_to_move = $this->_queue[$from_position];
		for ($i = 0; $i < $this->size(); $i++) {
			if($from_position == $i ) {
				continue;
			} elseif ($to_position == $i) {
				array_push($temp_queue, $element_to_move);
			}
			array_push($temp_queue, $this->_queue[$i]);
		}
		//$this->_queue = array();
		$this->_queue = $temp_queue;
	
		//maybe using array_splice
		
	}
	
	public function swap($position1, $position2) {
		if(!isset($position1)) {
			return "Please select a valid position 1";
		}
		if(!isset($position2)) {
			return "Please select a valid position 2";
		}
		if ($position1 == $position2) {
			"Please select different user";
		}
		$element_postion1 = $this->_queue[$position1];
		$this->_queue[$position1] = $this->_queue[$position2];
		$this->_queue[$position2] = $element_postion1;	
	}
	
	public function printQueue() {
		
	}
}




?>