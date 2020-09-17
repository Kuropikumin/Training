require 'spec_helper'

RSpec.describe '四則演算' do
  it '加算：1 + 1 = 2' do
    expect( 1 + 1 ).to eq 2
  end
  it '減算：5 - 1 = 4' do
    expect( 5 - 1 ).to eq 4
  end
  it '乗算：2 * 3 = 6' do
    expect( 2*3 ).to eq 6
  end
end
