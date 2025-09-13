import threading
import queue


class UserInput:
    def __init__(self):
        self.queue = queue.Queue()
        self._stop = False
        self.thread = threading.Thread(target=self._read_input, daemon=True)
        self.thread.start()

    def _read_input(self):
        while not self._stop:
            data = input("Enter velocities (linear_x,linear_y,angular) or q to quit: ")
            self.queue.put(data)

    def get_data(self):
        """Return latest input if available, else None"""
        try:
            return self.queue.get_nowait()
        except queue.Empty:
            return None

    def stop(self):
        self._stop = True
        self.thread.join()
