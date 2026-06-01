public class CounterDemo {

    private static final Object lock = new Object();
    private static boolean firstDone = false;

    public static void main(String[] args) {
        Thread countUpThread = new Thread(new CountUpTask(), "CountUpThread");
        Thread countDownThread = new Thread(new CountDownTask(), "CountDownThread");

        countUpThread.start();
        countDownThread.start();

        try {
            countUpThread.join();
            countDownThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.err.println("Main thread interrupted: " + e.getMessage());
        }

        System.out.println("Both threads have finished.");
    }

    // Thread 1: counts from 0 to 20
    private static class CountUpTask implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i <= 20; i++) {
                synchronized (lock) {
                    System.out.println(Thread.currentThread().getName() + " -> " + i);
                }
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return;
                }
            }

            synchronized (lock) {
                firstDone = true;
                lock.notifyAll();
            }
        }
    }

    // Thread 2: waits until firstDone == true, then counts from 20 down to 0
    private static class CountDownTask implements Runnable {
        @Override
        public void run() {
            synchronized (lock) {
                while (!firstDone) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        return;
                    }
                }
            }

            for (int i = 20; i >= 0; i--) {
                synchronized (lock) {
                    System.out.println(Thread.currentThread().getName() + " -> " + i);
                }
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return;
                }
            }
        }
    }
}

