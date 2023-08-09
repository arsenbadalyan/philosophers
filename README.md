# Dining Philosophers Problem Solutions

**Author:** Arsen Badalyan

This repository provides concurrent solutions to the Dining Philosophers problem using two different synchronization mechanisms: threads with mutexes and processes with semaphores. The solutions are designed to ensure that philosophers can dine without conflicts and deadlocks.

## Problem Description

The Dining Philosophers problem is a classic synchronization challenge that involves a group of philosophers sitting at a table with a bowl of spaghetti and a fork between each pair of philosophers. Philosophers alternate between thinking and eating, but they require both the left and right forks to eat. The challenge lies in preventing deadlocks and ensuring efficient resource management.

## Solutions

### Threads with Mutexes

In this solution, philosophers are represented as threads, and mutexes are employed to regulate access to forks. By using mutexes, the implementation guarantees that only one philosopher can hold a fork at any given time, avoiding conflicts and deadlocks.

### Processes with Semaphores

The process-based solution models philosophers as separate processes and utilizes semaphores for synchronization. Semaphores enable controlled access to forks, ensuring that philosophers can acquire the required forks without conflicting with each other.

## Getting Started

1. Clone this repository using `git clone`.
2. Navigate to the appropriate solution directory (`threads-mutexes` or `processes-semaphores`).
3. Compile the code using make command.

## Usage and Contributions

This project is intended as a learning resource for those interested in concurrent programming, synchronization, and parallel computing. Feel free to study the solutions, experiment with modifications, and contribute improvements through pull requests.

## License

This project is licensed under the [MIT License](LICENSE), allowing you to use and modify the code as needed.

---

Explore the world of concurrent programming and synchronization with these Dining Philosophers problem solutions. If you have questions or suggestions, don't hesitate to reach out and contribute!
