circuit cic_filter_top :
  module cic_filter_top :
    input clk : UInt<1>
    input reset_n : UInt<1>
    input data_in : UInt<1>
    output data_out : UInt<19>
    input data_en : UInt<1>

    node _T = asClock(clk) @[cic_filter.scala 24:27]
    node _T_1 = not(reset_n) @[cic_filter.scala 24:36]
    node _T_2 = asAsyncReset(_T_1) @[cic_filter.scala 24:45]
    reg counter_a : UInt<6>, _T with :
      reset => (_T_2, UInt<6>("h0")) @[Counter.scala 62:40]
    wire counter_b : UInt<1>
    counter_b <= UInt<1>("h0")
    when data_en : @[Counter.scala 120:16]
      node wrap_wrap = eq(counter_a, UInt<6>("h3f")) @[Counter.scala 74:24]
      node _wrap_value_T = add(counter_a, UInt<1>("h1")) @[Counter.scala 78:24]
      node _wrap_value_T_1 = tail(_wrap_value_T, 1) @[Counter.scala 78:24]
      counter_a <= _wrap_value_T_1 @[Counter.scala 78:15]
      counter_b <= wrap_wrap @[Counter.scala 120:23]
    reg sum_0 : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 29:38]
    reg sum_1 : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 29:38]
    reg sum_2 : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 29:38]
    node _sum_0_T = add(sum_0, data_in) @[cic_filter.scala 35:42]
    node _sum_0_T_1 = tail(_sum_0_T, 1) @[cic_filter.scala 35:42]
    sum_0 <= _sum_0_T_1 @[cic_filter.scala 35:28]
    node _sum_1_T = add(sum_0, sum_1) @[cic_filter.scala 37:46]
    node _sum_1_T_1 = tail(_sum_1_T, 1) @[cic_filter.scala 37:46]
    sum_1 <= _sum_1_T_1 @[cic_filter.scala 37:28]
    node _sum_2_T = add(sum_1, sum_2) @[cic_filter.scala 37:46]
    node _sum_2_T_1 = tail(_sum_2_T, 1) @[cic_filter.scala 37:46]
    sum_2 <= _sum_2_T_1 @[cic_filter.scala 37:28]
    node _sum_out_T = add(sum_2, sum_1) @[cic_filter.scala 40:34]
    node sum_out = tail(_sum_out_T, 1) @[cic_filter.scala 40:34]
    wire sub_next : UInt<19>[3] @[cic_filter.scala 44:28]
    reg sub_0 : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 45:38]
    reg sub_1 : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 45:38]
    reg sub_2 : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 45:38]
    reg sub_out : UInt<19>, _T with :
      reset => (_T_2, UInt<19>("h0")) @[cic_filter.scala 46:30]
    node _sub_next_0_T = sub(sum_out, sub_0) @[cic_filter.scala 50:44]
    node _sub_next_0_T_1 = tail(_sub_next_0_T, 1) @[cic_filter.scala 50:44]
    sub_next[0] <= _sub_next_0_T_1 @[cic_filter.scala 50:33]
    sub_0 <= sum_out @[cic_filter.scala 51:28]
    node _sub_next_1_T = sub(sub_next[0], sub_1) @[cic_filter.scala 53:56]
    node _sub_next_1_T_1 = tail(_sub_next_1_T, 1) @[cic_filter.scala 53:56]
    sub_next[1] <= _sub_next_1_T_1 @[cic_filter.scala 53:33]
    sub_1 <= sub_next[0] @[cic_filter.scala 54:28]
    node _sub_next_2_T = sub(sub_next[1], sub_2) @[cic_filter.scala 53:56]
    node _sub_next_2_T_1 = tail(_sub_next_2_T, 1) @[cic_filter.scala 53:56]
    sub_next[2] <= _sub_next_2_T_1 @[cic_filter.scala 53:33]
    sub_2 <= sub_next[1] @[cic_filter.scala 54:28]
    data_out <= sub_out @[cic_filter.scala 57:18]
    node _sub_out_T = mux(counter_b, sub_next[2], sub_out) @[cic_filter.scala 58:23]
    sub_out <= _sub_out_T @[cic_filter.scala 58:17]

