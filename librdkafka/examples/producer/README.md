# Simple producer

## Setup Kafka

Follow the instructions above to install a local instance or use Confluent Cloud (or any other service)

### Run a local instance

#### Start the instance on the default plaintext port
```
$ confluent local kafka start --plaintext-ports 9092
The local commands are intended for a single-node development environment only, NOT for production usage. See more: https://docs.confluent.io/current/cli/index.html


Pulling from confluentinc/confluent-local
Digest: sha256:ad62269bf4766820c298f7581cf872a49f46a11dbaebcccb4fd2e71049288c5b
Status: Image is up to date for confluentinc/confluent-local:7.6.0
+-----------------+------+
| Kafka REST Port | 8082 |
| Plaintext Ports | 9092 |
+-----------------+------+
```
#### Create a test topic and "consume" on it

```
$ confluent local kafka topic create TOPIC
Created topic "TOPIC".
root@davids-legion9:/home/david# confluent kafka topic consume TEST --bootstrap localhost:9092 --protocol PLAINTEXT
Starting Kafka Consumer. Use Ctrl-C to exit.
Message from ESP32
```

#### Note the IP address of your instance

## Run ESP32 program

You need to have an ESP32 with PSRAM
1) Update the program with the IP address of the local instance
2) Build and Run the program:

```
I (1873) wifi:wifi certification version: v7.0
I (1873) wifi:config NVS flash: enabled
I (1873) wifi:config nano formatting: disabled
I (1883) wifi:Init data frame dynamic rx buffer num: 32
I (1883) wifi:Init static rx mgmt buffer num: 5
I (1883) wifi:Init management short buffer num: 32
I (1893) wifi:Init static tx buffer num: 16
I (1893) wifi:Init tx cache buffer num: 32
I (1903) wifi:Init static rx buffer size: 1600
I (1903) wifi:Init static rx buffer num: 10
I (1913) wifi:Init dynamic rx buffer num: 32
I (4503) wifi:dp: 1, bi: 102400, li: 3, scale listen interval from 307200 us to 307200 us
I (4513) wifi:AP's beacon interval = 102400 us, DTIM period = 1
I (7033) esp_netif_handlers: example_netif_sta ip: 192.168.0.39, mask: 255.255.255.0, gw: 192.168.0.1
I (7033) example_connect: Got IPv4 event: Interface "example_netif_sta" address: 192.168.0.39
I (7033) example_common: Connected to example_netif_sta
I (7043) example_common: - IPv4 address: 192.168.0.39,
I (7043) example_common: - IPv6 address: fe80:0000:0000:0000:c6dd:57ff:fe5f:2cc4, type: ESP_IP6_ADDR_IS_LINK_LOCAL
name: localhost
WARNING: librdkafka: rd_kafka_socket_cb_generic: fcntl(FD_CLOEXEC) failed: Function not implemented: ignoring
% Type some text and hit enter to produce message
% Or just hit enter to only serve delivery reports
% Press Ctrl-C or Ctrl-D to exit
I (7183) producer: Message from ESP32 18
% Enqueued message (18 bytes) for topic TEST
% Flushing final messages..
name: localhost
WARNING: librdkafka: rd_kafka_socket_cb_generic: fcntl(FD_CLOEXEC) failed: Function not implemented: ignoring
% Message delivered (18 bytes, partition 0)
Producer returned 0
I (7633) main_task: Returned from app_main()
```
