require 'spec_helper'

RSpec.describe User do
  describe '#greet method' do
    before do
      @params = { name: 'たろう' }
    end
    context 'ageが12以下の場合' do
      before do
        @params.merge!( age: 12 )
      end
      it '挨拶がひらがなになる' do
        user = User.new( @params )
        expect( user.greet ).to eq 'ぼくはたろうだよ。'
      end
    end
    context 'ageが13以上の場合' do
      before do
        @params.merge!( age: 13 )
      end
      it '挨拶が漢字になる' do
        user = User.new( @params )
        expect( user.greet ).to eq '僕はたろうです。'
      end
    end
  end
end
