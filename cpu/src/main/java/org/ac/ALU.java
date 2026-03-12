package org.ac;

import static org.ac.Register.GP_REGISTER_SIZE;

/**
 * The class the implements the Arithmetic and Login Unit (ALU)
 */
public class ALU {
    
    enum Flags {
        NEGATIVE,
        ZERO,
        CARRY,
        OVERFLOW
    }

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
        out.set(~in.getInt());
        setNegativeFlag(out.getBit(0));
        setZeroFlag(out.getInt() == 0);
    }

    /**
     * Stores in register out the result of the bitwise logical AND between rin1 and rin2.
     * Assume that all registers have the same size.
     */
    public void and(Register out, Register in1, Register in2) {
        out.set(in1.getInt() & in2.getInt());
        setNegativeFlag(out.getBit(0));
        setZeroFlag(out.getInt() == 0);
    }

    /**
     * Stores in register out the result of the bitwise logical OR between rin1 and rin2.
     * Assume that all registers have the same size.
     */
    public void or(Register out, Register in1, Register in2) {
        out.set(in1.getInt() | in2.getInt());
        setNegativeFlag(out.getBit(0));
        setZeroFlag(out.getInt() == 0);
    }

    /**
     * Stores in register out the result of the bitwise logical XOR between rin1 and rin2.
     * Assume that all registers have the same size.
     */
    public void xor(Register out, Register in1, Register in2) {
        out.set(in1.getInt() ^ in2.getInt());
    }

    /**
     * Stores in register out the result of a logical shift left operation on register in.
     * Assume that both registers have the same size.
     */
    public void lsl(Register out, Register in, int n) {
        out.set(in.getInt() << n);

        setNegativeFlag(out.getBit(0));
        setZeroFlag(out.getInt() == 0);
        setCarryFlag(in.getBit(n-1));
        setOverflowFlag(in.getBit(n) ^ carryFlag());
    }

    /**
     * Stores in register out the result of the arithmetic negation of in (two’s complement).
     * Assume that both registers have the same size.
     */
    public void neg(Register out, Register in) {
        out.set(~in.getInt()+1);
    }

    /**
     * Implements a Ripple Carry Adder (manually handling carries) to compute out = in1 + in2.
     * Assume that all registers have the same size.
     */
    public void add(Register out, Register in1, Register in2) {
        boolean carry_in = false;
        boolean carry_out = false;

        for (int i = out.size()-1; i >= 0; i--) {
            carry_in = carry_out;
            boolean bit1 = in1.getBit(i);
            boolean bit2 = in2.getBit(i);
            boolean value = bit1 ^ bit2 ^ carry_in;
            carry_out = ((carry_in && (bit1 || bit2)) || (bit1 && bit2));
            out.setBit(i, value);
        }
        setNegativeFlag(out.getBit(0));
        setZeroFlag(out.getInt() == 0);
        setCarryFlag(carry_out);
        setOverflowFlag(carry_in ^ carry_out);
        System.out.println(out.getInt());

    }

    /**
     * Return the value of the Negative flag
     */
    public boolean negativeFlag() {
        return NZCV.getBit(Flags.NEGATIVE.ordinal());
    }

    private void setNegativeFlag(boolean flag) {
        NZCV.setBit(Flags.NEGATIVE.ordinal(), flag);
    }

    /**
     * Return the value of the Zero flag
     */
    public boolean zeroFlag() {
        return NZCV.getBit(Flags.ZERO.ordinal());
    }

    private void setZeroFlag(boolean flag) {
        NZCV.setBit(Flags.ZERO.ordinal(), flag);
    }

    /**
     * Return the value of the Carry flag
     */
    public boolean carryFlag() {
        return NZCV.getBit(Flags.CARRY.ordinal());
    }

    private void setCarryFlag(boolean flag) {
        NZCV.setBit(Flags.CARRY.ordinal(), flag);
    }
    /**
     * Return the value of the Overflow flag
     */
    public boolean overflowFlag() {
        return NZCV.getBit(Flags.OVERFLOW.ordinal());
    }

    private void setOverflowFlag(boolean flag) {
        NZCV.setBit(Flags.OVERFLOW.ordinal(), flag);
    }
}
