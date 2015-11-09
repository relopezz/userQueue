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
		return array_unshift($this->_queue, $value);	
	}

	public function removeUsers($user) {
		$current_size = $this->size(); 
		while($current_size > 0) {
			$user_in_queue = $this->pop();
			if ($user_in_queue == $user) {
				$deleted =  $user_in_queue;
			} else {
				$this->add($user_in_queue);
			}
			$current_size--;
		}
		return $deleted;
	}
	
	public function reverseQ() {
		$this->_queue = array_reverse($this->_queue);
		return $this;
	}
}

