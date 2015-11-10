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

	//Tasks
	public function add($value = NULL) {
		if ($value == NULL) {
			return "Please select a value";
		}
		return array_unshift($this->_queue, $value);
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
		echo $user;
		if ( $index !== false ) {
			$this->removeByPosition($index);
			return "User removed";
		} else {
			return "Please select a valid user";
		}
	}
	
	public function swap($position1, $position2) {
		if(isset($position1)) {
			return "Please select a valid position 1";
		}
		if(isset($position2)) {
			return "Please select a valid position 2";
		}
		if ($position1 == $position2) {
			return "Please select different user";
		}
		$element_postion1 = $this->_queue[$position1];
		$this->_queue[$position1] = $this->_queue[$position2];
		$this->_queue[$position2] = $element_postion1;
		
		return "Successfully";
	}
	
	public function move($from_position, $to_position) {
		
    	if (!isset($this->_queue[$from_position])) {
        	return "The position selected does not exists";
    	}
    
    	array_splice($this->_queue, (($to_position-1 > 0) ? $to_position : 0), 0, array_splice($this->_queue, $from_position, 1));
    	return $this->_queue;
	}
		
	public function printQueue() {
		$json_string = json_encode($this->_queue, JSON_FORCE_OBJECT);
		echo $json_string;
	}
	
	public function printPrettyQueue() {
		$string = "{Position} : {UserId}<br />\n";
		foreach($this->_queue as $key => $value) {
			$string .= "{".$key."}:{ ".$this->pop()."}<br />\n";
		}
		
		return $string;
	}
}
