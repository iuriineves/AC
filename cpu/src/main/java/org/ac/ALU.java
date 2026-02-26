package org.ac;

import static org.ac.Register.GP_REGISTER_SIZE;

/**
 * The class the implements the Arithmetic and Login Unit (ALU)
 */
public class ALU {

    /**
     *  Flags register.
     *  Bit 0 (Negative): Set if the result of the last operation executed by the ALU is negative, that is,
     *                    that MSB of the register holding the result is 1.
     *  Bit 1 (Zero): Set if the result of the last operation was exactly zero.
     *  Bit 2 (Carry): Set if a carry occurred in the last operation executed by the ALU.
     *  Bit 3 (Overflow): et if an arithmetic overflow occurred in the last operation executed by the ALU.
     */
    final Register NZCV = new Register(GP_REGISTER_SIZE);

    /**
     * Stores in register out the result of the bitwise inversion of register in (one’s complement).
     * Assume that both registers have the same size.
     */
    public void not(Register out, Register in) {
        // TODO
    }

    /**
     * Stores in register out the result of the bitwise logical AND between rin1 and rin2.
     * Assume that all registers have the same size.
     */
    public void and(Register out, Register in1, Register in2) {
        // TODO
    }

    /**
     * Stores in register out the result of the bitwise logical OR between rin1 and rin2.
     * Assume that all registers have the same size.
     */
    public void or(Register out, Register in1, Register in2) {
        // TODO
    }

    /**
     * Stores in register out the result of the bitwise logical XOR between rin1 and rin2.
     * Assume that all registers have the same size.
     */
    public void xor(Register out, Register in1, Register in2) {
        // TODO
    }

    /**
     * Stores in register out the result of a logical shift left operation on register in.
     * Assume that both registers have the same size.
     */
    public void lsl(Register out, Register in, int n) {
        // TODO
    }

    /**
     * Stores in register out the result of the arithmetic negation of in (two’s complement).
     * Assume that both registers have the same size.
     */
    public void neg(Register out, Register in) {
        // TODO
    }

    /**
     * Implements a Ripple Carry Adder (manually handling carries) to compute out = in1 + in2.
     * Assume that all registers have the same size.
     */
    public void add(Register out, Register in1, Register in2) {
        // TODO
    }

    /**
     * Return the value of the Negative flag
     */
    public boolean negativeFlag() {
        // TODO
        boolean todo = false;
        return todo;
    }

    /**
     * Return the value of the Zero flag
     */
    public boolean zeroFlag() {
        // TODO
        boolean todo = false;
        return todo;
    }

    /**
     * Return the value of the Carry flag
     */
    public boolean carryFlag() {
        // TODO
        boolean todo = false;
        return todo;
    }

    /**
     * Return the value of the Overflow flag
     */
    public boolean overflowFlag() {
        // TODO
        boolean todo = false;
        return todo;
    }

}
