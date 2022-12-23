module cic_filter_top(
  input         clk,
  input         reset_n,
  input         data_in,
  output [18:0] data_out,
  input         data_en
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT
  wire  _T_2 = ~reset_n; // @[cic_filter.scala 24:45]
  reg [5:0] counter_a; // @[Counter.scala 62:40]
  wire  wrap_wrap = counter_a == 6'h3e; // @[Counter.scala 74:24]
  wire [5:0] _wrap_value_T_1 = counter_a + 6'h1; // @[Counter.scala 78:24]
  reg [18:0] sum_0; // @[cic_filter.scala 29:38]
  reg [18:0] sum_1; // @[cic_filter.scala 29:38]
  reg [18:0] sum_2; // @[cic_filter.scala 29:38]
  wire [18:0] _GEN_3 = {{18'd0}, data_in}; // @[cic_filter.scala 35:42]
  wire [18:0] sum_out = sum_2 + sum_1; // @[cic_filter.scala 40:34]
  wire  _T_3 = data_en & wrap_wrap; // @[cic_filter.scala 43:37]
  reg [18:0] sub_0; // @[cic_filter.scala 45:42]
  reg [18:0] sub_1; // @[cic_filter.scala 45:42]
  reg [18:0] sub_2; // @[cic_filter.scala 45:42]
  wire [18:0] sub_next_0 = sum_out - sub_0; // @[cic_filter.scala 49:48]
  wire [18:0] sub_next_1 = sub_next_0 - sub_1; // @[cic_filter.scala 52:60]
  assign data_out = sub_next_1 - sub_2; // @[cic_filter.scala 52:60]
  always @(posedge clk or posedge _T_2) begin
    if (_T_2) begin // @[Counter.scala 120:16]
      counter_a <= 6'h0; // @[Counter.scala 78:15 88:{20,28}]
    end else if (data_en) begin // @[Counter.scala 62:40]
      if (wrap_wrap) begin
        counter_a <= 6'h0;
      end else begin
        counter_a <= _wrap_value_T_1;
      end
    end
  end
  always @(posedge clk or posedge _T_2) begin
    if (_T_2) begin // @[cic_filter.scala 35:42]
      sum_0 <= 19'h0;
    end else begin
      sum_0 <= sum_0 + _GEN_3;
    end
  end
  always @(posedge clk or posedge _T_2) begin
    if (_T_2) begin // @[cic_filter.scala 37:46]
      sum_1 <= 19'h0;
    end else begin
      sum_1 <= sum_0 + sum_1;
    end
  end
  always @(posedge clk or posedge _T_2) begin
    if (_T_2) begin // @[cic_filter.scala 37:46]
      sum_2 <= 19'h0;
    end else begin
      sum_2 <= sum_1 + sum_2;
    end
  end
  always @(posedge _T_3 or posedge _T_2) begin
    if (_T_2) begin // @[cic_filter.scala 40:34]
      sub_0 <= 19'h0;
    end else begin
      sub_0 <= sum_2 + sum_1;
    end
  end
  always @(posedge _T_3 or posedge _T_2) begin
    if (_T_2) begin // @[cic_filter.scala 49:48]
      sub_1 <= 19'h0;
    end else begin
      sub_1 <= sum_out - sub_0;
    end
  end
  always @(posedge _T_3 or posedge _T_2) begin
    if (_T_2) begin // @[cic_filter.scala 52:60]
      sub_2 <= 19'h0;
    end else begin
      sub_2 <= sub_next_0 - sub_1;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  counter_a = _RAND_0[5:0];
  _RAND_1 = {1{`RANDOM}};
  sum_0 = _RAND_1[18:0];
  _RAND_2 = {1{`RANDOM}};
  sum_1 = _RAND_2[18:0];
  _RAND_3 = {1{`RANDOM}};
  sum_2 = _RAND_3[18:0];
  _RAND_4 = {1{`RANDOM}};
  sub_0 = _RAND_4[18:0];
  _RAND_5 = {1{`RANDOM}};
  sub_1 = _RAND_5[18:0];
  _RAND_6 = {1{`RANDOM}};
  sub_2 = _RAND_6[18:0];
`endif // RANDOMIZE_REG_INIT
  if (_T_2) begin
    counter_a = 6'h0;
  end
  if (_T_2) begin
    sum_0 = 19'h0;
  end
  if (_T_2) begin
    sum_1 = 19'h0;
  end
  if (_T_2) begin
    sum_2 = 19'h0;
  end
  if (_T_2) begin
    sub_0 = 19'h0;
  end
  if (_T_2) begin
    sub_1 = 19'h0;
  end
  if (_T_2) begin
    sub_2 = 19'h0;
  end
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
