import numpy as np
import time

def snc(x: str) -> int:
    if x.startswith('-'):
        return int(x)
    return int(x.strip())

def get(number: int, endtime: list):
    name = f"test{number}.inp"
    
    vi = []
    with open(name, "r") as nowfile:
        for num in nowfile:
            vi.append(snc(num))
    
    start = time.time()  # get starting timepoint
    
    # ----sorting here-----
    vi = np.sort(np.array(vi))
    # ----------------------
    
    stop = time.time()  # end timepoint
    duration = int((stop - start) * 1000)  # Convert to milisecond
    
    endtime.append(duration)

def get_time():
    endtime = []
    for i in range(10):
        get(i, endtime)
    return endtime

def printf_time():
    endtime = get_time()
    with open("Report.txt", "w") as myfile:
        for i, time in enumerate(endtime):
            myfile.write(f"Time to run test {i} is: {time}\n")
        
        average = sum(endtime) // len(endtime)
        myfile.write(f"Average is: {average}\n")

def main():
    printf_time()

if __name__ == "__main__":
    main()