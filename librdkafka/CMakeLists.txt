set(kafka_dir librdkafka/src/)

set(sources
        crc32c.c
        rdaddr.c
        rdavl.c
        rdbuf.c
        rdcrc32.c
        rdfnv1a.c
        rdbase64.c
        rdkafka.c
        rdkafka_assignor.c
        rdkafka_broker.c
        rdkafka_buf.c
        rdkafka_cgrp.c
        rdkafka_conf.c
        rdkafka_event.c
        rdkafka_feature.c
        rdkafka_lz4.c
        rdkafka_metadata.c
        rdkafka_metadata_cache.c
        rdkafka_msg.c
        rdkafka_msgset_reader.c
        rdkafka_msgset_writer.c
        rdkafka_offset.c
        rdkafka_op.c
        rdkafka_partition.c
        rdkafka_pattern.c
        rdkafka_queue.c
        rdkafka_range_assignor.c
        rdkafka_request.c
        rdkafka_roundrobin_assignor.c
        rdkafka_sasl.c
        rdkafka_sasl_plain.c
        rdkafka_sticky_assignor.c
        rdkafka_subscription.c
        rdkafka_assignment.c
        rdkafka_timer.c
        rdkafka_topic.c
        rdkafka_transport.c
        rdkafka_interceptor.c
        rdkafka_header.c
        rdkafka_admin.c
        rdkafka_aux.c
        rdkafka_background.c
        rdkafka_idempotence.c
        rdkafka_txnmgr.c
        rdkafka_cert.c
        rdkafka_coord.c
        rdkafka_mock.c
        rdkafka_mock_handlers.c
        rdkafka_mock_cgrp.c
        rdkafka_error.c
        rdkafka_fetcher.c
        rdkafka_telemetry.c
        rdkafka_telemetry_decode.c
        rdkafka_telemetry_encode.c
        nanopb/pb_encode.c
        nanopb/pb_decode.c
        nanopb/pb_common.c
        opentelemetry/metrics.pb.c
        opentelemetry/common.pb.c
        opentelemetry/resource.pb.c
        rdlist.c
        rdlog.c
        rdmurmur2.c
        rdports.c
        rdrand.c
        rdregex.c
        rdstring.c
        rdunittest.c
        rdvarint.c
        rdmap.c
        snappy.c
        tinycthread.c
        tinycthread_extra.c
        rdxxhash.c
        cJSON.c
)


list(TRANSFORM sources PREPEND ${kafka_dir})

idf_component_register(SRCS ${sources}
                       INCLUDE_DIRS "port/include" ${kafka_dir})

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-incompatible-pointer-types")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-error=char-subscripts")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-error=maybe-uninitialized")
