import time
import datetime
import csv
from labjack import ljm

# Open the LabJack T4 device
handle = ljm.openS("T4", "USB", "ANY")

# Configure the analog input channels
ain_channels = ["AIN0", "AIN3"] # AIN0 is the current channel
num_channels = len(ain_channels)

# Set up the CSV file
csv_filename = "voltage_measurements.csv"
csv_header = ["timestamp"] + ["Source Current (mA)"] + ["Source Voltage (V)"]
with open(csv_filename, mode='w', newline='') as csv_file:
    writer = csv.writer(csv_file)
    writer.writerow(csv_header)

# Main loop
while True:
    # Get the current timestamp
    timestamp = time.time()

    # Read the voltages on the analog input channels
    voltages = [ljm.eReadName(handle, channel) for channel in ain_channels]

    # Convert AIN0 voltage measurement to current value in mA: I = V / (20 * 5.9) = V / 118, mA = 8.475 * volts
    voltages[0] = 8.475 * voltages[0]

    # Convert the timestamp to a human-readable format
    dt = datetime.datetime.fromtimestamp(timestamp)
    timestamp_str = dt.isoformat(timespec='milliseconds')

    # Print the voltages (optional)
    # print("Timestamp: {}".format(timestamp_str))
    # for i in range(num_channels):
    #     print("{}: {:.3f} V".format(ain_channels[i], voltages[i]))

    # Write the data to the CSV file
    with open(csv_filename, mode='a', newline='') as csv_file:
        writer = csv.writer(csv_file)
        writer.writerow([timestamp_str] + voltages)

    # Wait for 60 seconds before taking the next measurement
    time.sleep(60)

