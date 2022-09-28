module Multiply_4_bit(
  input [3:0] X, Y, 
  input clk, start, 
  output [7:0] P, 
  output stop
); 
/*
initial begin
  stop = 1'b0;
end
*/
wire [4:0]a0, a1, a2, a3, a4;
wire [3:0]q0;
wire [3:0]b;
wire [4:0]s0, s1, s2, s3;  
wire [4:0]o_a0, o_a1, o_a2, o_a3;
wire [3:0]o_q0, o_q1, o_q2, o_q3;
    
    alw_stop  clk_stop(.clk(clk), .stop(stop));
    reg_5_bit acc0(.a(5'b0), .start(start), .clk(clk), .ac(a0)); // a0 = 00000
    reg_4_bit q0_(.x(Y), .start(start), .clk(clk), .b(q0)); //q0 = Y
    reg_4_bit b0(.x(X), .start(start), .clk(clk), .b(b)); // b = X
    
    add_acc_b s_0(.en(q0[0]), .start(start), .clk(clk), .acc(a0), .b({1'b0,b}), .s(s0)); // s0 = q0[0] ? a0 + b : a0 
    reg_5_bit acc1(.a(s0), .start(start), .clk(clk), .ac(a1)); // a1 = s0
    reg_shift sh0(.acc(a1), .q(q0), .clk(clk), .start(start), .o_acc(o_a0), .o_q(o_q0)); // {o_a0, o_q0} = {a1, q0} >> 1
    
    add_acc_b s_1(.en(o_q0[0]), .start(start), .clk(clk), .acc(o_a0), .b({1'b0,b}), .s(s1)); // s1 = o_q0[0] ? o_a0 + b : o_a0
    reg_5_bit acc2(.a(s1), .start(start), .clk(clk), .ac(a2)); // a2 = s1
    reg_shift sh1(.acc(a2), .q(o_q0), .clk(clk), .start(start), .o_acc(o_a1), .o_q(o_q1)); //  {o_a1, o_q1} = {a2, o_q0} >> 1
 
    add_acc_b s_2(.en(o_q1[0]), .start(start), .clk(clk), .acc(o_a1), .b({1'b0,b}), .s(s2)); // s2 = o_q1[0] ? o_a1 + b : o_a1
    reg_5_bit acc3(.a(s2), .start(start), .clk(clk), .ac(a3)); // a3 = s2
    reg_shift sh2(.acc(a3), .q(o_q1), .clk(clk), .start(start), .o_acc(o_a2), .o_q(o_q2)); // {o_a2, o_q2} = {a3, o_q1} >> 1    

    add_acc_b s_3(.en(o_q2[0]), .start(start), .clk(clk), .acc(o_a2), .b({1'b0,b}), .s(s3)); // s3 = o_q2[0] ? o_a2 + b : o_a2
    reg_5_bit acc4(.a(s3), .start(start), .clk(clk), .ac(a4));  // a4 = s3 
    reg_shift sh3(.acc(a4), .q(o_q2), .clk(clk), .start(start), .o_acc(o_a3), .o_q(o_q3)); // {o_a3, o_q3} = {a4, o_q2} >> 1
    
    //assign P = {o_a3[3:0], o_q3};
    concat_4_4_bit concat_a_q(.start(start),.a(o_a3[3:0]), .q(o_q3), .clk(clk), .p(P), .stop(stop));
    //assign stop = 1;
always @(clk) begin
  $display("a0=%b q0=%b b=%b",a0,q0,b);
end
endmodule